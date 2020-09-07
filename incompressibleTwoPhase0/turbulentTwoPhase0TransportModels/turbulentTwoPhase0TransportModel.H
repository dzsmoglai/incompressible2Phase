/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2015-2016 OpenFOAM Foundation
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

Typedef
    Foam::incompressible::turbulenceModel

Typedef
    Foam::incompressible::twoPhaseRASModel

Typedef
    Foam::incompressible::LESModel

Description
    Typedefs for turbulence, twoPhaseRAS and LES models for incompressible flow
    based on the standard laminar transport package.

SourceFiles
    turbulentTwoPhaseTransportModel.C
    turbulentTwoPhaseTransportModels.C

\*---------------------------------------------------------------------------*/

#ifndef turbulentTwoPhase0TransportModel_H
#define turbulentTwoPhase0TransportModel_H

#include "IncompressibleTwoPhase0TurbulenceModel.H"
//#include "laminarModel.H"
#include "RASModel.H"
//#include "LESModel.H"
#include "incompressible/transportModel/transportModel.H"//try to keep and reuse it

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    namespace incompressibleTwoPhase0
    {
        typedef IncompressibleTwoPhase0TurbulenceModel<transportModel> turbulenceModel;

        //typedef laminarModel<turbulenceModel> laminarModel;
        typedef RASModel<turbulenceModel> RASModel;
        //typedef LESModel<turbulenceModel> LESModel;

        template<class BasicCompressibleTurbulenceModel>
        autoPtr<BasicCompressibleTurbulenceModel> New
        (
            const volScalarField& rho,
            const volVectorField& U,
            const surfaceScalarField& alphaRhoPhi,
            const surfaceScalarField& phi,
            const typename BasicCompressibleTurbulenceModel::transportModel&
                transport,
            const word& propertiesName = turbulenceModel::propertiesName
        );
    }
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
    #include "turbulentTwoPhase0TransportModel.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
