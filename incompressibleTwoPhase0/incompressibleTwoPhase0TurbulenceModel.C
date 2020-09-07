/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2013-2014 OpenFOAM Foundation
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

#include "incompressibleTwoPhase0TurbulenceModel.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(incompressibleTwoPhase0TurbulenceModel, 0);
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::incompressibleTwoPhase0TurbulenceModel::incompressibleTwoPhase0TurbulenceModel
(
    const volScalarField& rho,//change from geometricOneField to volScalarField;
    const volVectorField& U,
    const surfaceScalarField& alphaRhoPhi,
    const surfaceScalarField& phi,
    const word& propertiesName
)
:
    turbulenceModel
    (
        U,
        alphaRhoPhi,
        phi,
        propertiesName
    ),
    rho_(rho)
{}


Foam::tmp<Foam::volScalarField>
Foam::incompressibleTwoPhase0TurbulenceModel::mu() const
{
    return nu()*this->rho_;
}


Foam::tmp<Foam::scalarField>
Foam::incompressibleTwoPhase0TurbulenceModel::mu(const label patchi) const
{
    return nu(patchi)*this->rho_.boundaryField()[patchi];
}


Foam::tmp<Foam::volScalarField>
Foam::incompressibleTwoPhase0TurbulenceModel::mut() const
{
    return nut()*this->rho_;
}


Foam::tmp<Foam::scalarField>
Foam::incompressibleTwoPhase0TurbulenceModel::mut(const label patchi) const
{
    return nut(patchi)*this->rho_.boundaryField()[patchi];
}


Foam::tmp<Foam::volScalarField>
Foam::incompressibleTwoPhase0TurbulenceModel::muEff() const
{
    return nuEff()*this->rho_;
}


Foam::tmp<Foam::scalarField>
Foam::incompressibleTwoPhase0TurbulenceModel::muEff(const label patchi) const
{
    return nuEff(patchi)*this->rho_.boundaryField()[patchi];
}


// ************************************************************************* //
