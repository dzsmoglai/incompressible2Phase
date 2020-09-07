The files in this folder are source codes of:
1. incompressibleTwoPhase0: a new libary of turbulence model, which includes mixture density into the turbulence transport equations.
2. inter0Foam, a modified version of the interFoam solver, which use the new turbulence library for the turbulence modelling, instead of the original "incompressible" turbulence model
3. interIso0Foam, a modified version of the interIsoFoam solver, which use the new turbulence library for the turbulence modelling, instead of the original "incompressible" turbulence model

To use the files:
copy the incompressibleTwoPhase0 to $FOAM_SRC/TurbulenceModels/ and use "wamke" commond to compile it.

copy the inter0Foam or the interIso0Foam to the $FOAM_APP/solvers/multiphase/ folder and use "wamke" commond to compile it.


contact: Zongshi Dong   dzs@whu.edu.cn
