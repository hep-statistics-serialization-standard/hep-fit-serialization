******************************
HEP fit serialization standard
******************************

Goal
====
HEP-fit-serialization standardizes the machine- and human-readable serialization of
all components involved in model fitting as used in High Energy Physics. This includes
the definition of the model, the data as well as the loss function.
The aim is to provide on one hand a language and
framework agnostic, machine-reabable and on the other hand a
human-readable, publishable and preservable representation. This would allow to interchange
the fitting framework and decouple the reproducibility from the frameworks lifetime.

The focus of this project is not on the long-term storage of large data, which may be
needed for an actual implementation, but rather
to define a common serialization format.

TODO: more description

Standard versions
=================

Until 1.x, the standard is considered unstable and may introduce backwards incompatible changes.

After that, backwords compatibility is guaranteed to be maintained inside the major releases (1.x, 2.x)
and should be kept, if possible, also between the major releases, but is not guaranteed in favor of a cleaner standard.

Participation
=============

In order to submit ideas, proposals and examples, you can either start a discussion using issues or
add the document(s), if you have some, in the 'standard' folder and create a PR to discussion them.

If you are interest to become part of the core committee, please open an issue. Anyone is allowed to join.

Contact
=======
To stay updated, you can sign up for the e-group: hep-statistics-serialization-standard@cern.ch

Involved projects
======================

zfit
----
A model fitting library in pure Python. It's
focus is on customizability and strong model building.

`zfit on Github <https://github.com/zfit/zfit>`_

pyhf
----
Pure-Python implementation of statistical model for multi-bin histogram-based analysis and its interval estimation;
HistFactory in Python.

`pyhf on Github <https://github.com/scikit-hep/pyhf>`_

RooFit
------
The Toolkit for Data Modeling with ROOT (RooFit) is a package that allows for modeling probability distributions in a compact and abstract way.

`RooFit <https://root.cern.ch/roofit>`_

Committee
=========

The comittee is responsible for the acceptance and denial of new proposals and has to approve a new version of the
standard.

Members:

.. include:: COMMITTEE.rst
