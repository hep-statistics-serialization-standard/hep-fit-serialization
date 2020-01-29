*********************
HEP fit serialization
*********************

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



Participating projects
======================

zfit
----
`zfit <https://github.com/zfit/zfit>`_ is a model fitting library in pure Python. It's
focus is on customizability and strong model building.

pyhf
----
TODO?

RooFit
------
TODO?
