/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2016 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "IncompressibleTwoPhase0TurbulenceModel.H"
#include "incompressible/transportModel/transportModel.H"//try to keep and reuse it.
#include "addToRunTimeSelectionTable.H"
#include "makeTurbulenceModel.H"

#include "RASModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

makeTurbulenceModelTypes
(
    geometricOneField,//change from geometricOneField to volScalarField;
    volScalarField,//change from geometricOneField to volScalarField;
    incompressibleTwoPhase0TurbulenceModel,//TwoPhase added
    IncompressibleTwoPhase0TurbulenceModel,//TwoPhase added
    transportModel
);
// change 'transportModelIncompressibleTurbulenceModel' to 'transportModelIncompressibleTwoPhaseTurbulenceModel'


#define makeRASModel(Type)                                                     \
    makeTemplatedTurbulenceModel                                               \
    (transportModelIncompressibleTwoPhase0TurbulenceModel, RAS, Type)


// ************************************************************************* //
