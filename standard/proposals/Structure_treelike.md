# Recursive, treelike structure

Tags: structure, meta
Status: planning
Authors: Jonas Eschle
Supporters: 


## Idea

The overall structure of the file should be treelike and have local responsibilities, e.g.
an object should know how to build itself given the configuration tree.

### Motivation

We don't want to restrict the possible models to a set defined by the standard but leave the
possiblity to use the same structure interchangeably with experimental features and
custom types.

The latter is quite important: if we have a pdf that is _not_ serializable, this can
still be coped with by defining whatever and load it from a e.g. Python script that
creates the object.

With this, we are sure to support anything.

### Content

A crucial element in every (sub)tree is therefore something like 'type'. This allows the parser/factory
to simply handover the (sub)tree to the correct, within the factory registered type-factory.

### Examples

somewhere in the tree:
```yaml
  type: JonasPDF
  odd_named_argument: 'hello world'
```

The parser should have a `JonasPDF` registered, together with a factory `JonasPDF_factory`, and simply hands over the 
remaining keywords to it.


## Implications

This implies that not every parser/framework can load every file. The framework has to define
which keywords are allowed.

On the other hand, a user can always register an additional pdf, e.g. one that
is created on a file in a script.

The downside is that this gives up the right of a fully centralized, global control.
