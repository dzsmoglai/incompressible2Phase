/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2013-2015 OpenFOAM Foundation
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

Class
    Foam::incompressibleTurbulenceModel

Description
    Abstract base class for turbulence models (RAS, LES and laminar).

SourceFiles
    incompressibleTwoPhaseTurbulenceModel.C

\*---------------------------------------------------------------------------*/

#ifndef incompressibleTwoPhase0TurbulenceModel_H
#define incompressibleTwoPhase0TurbulenceModel_H

#include "turbulenceModel.H"
#include "geometricOneField.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declarations
class fvMesh;

/*---------------------------------------------------------------------------*\
                Class incompressibleTwoPhaseTurbulenceModel Declaration
\*---------------------------------------------------------------------------*/

class incompressibleTwoPhase0TurbulenceModel
:
    public turbulenceModel
{

protected:

    // Protected data

        volScalarField rho_;   //change from geometricOneField to volScalarField


    // Protected member functions

        //- ***HGW Temporary function to be removed when the run-time selectable
        //  thermal transport layer is complete
        virtual void correctNut()
        {}


private:

    // Private Member Functions

        //- No copy construct
        incompressibleTwoPhase0TurbulenceModel
        (
            const incompressibleTwoPhase0TurbulenceModel&
        ) = delete;

        //- No copy assignment
        void operator=(const incompressibleTwoPhase0TurbulenceModel&) = delete;


public:

    //- Runtime type information
    TypeName("incompressibleTwoPhase0TurbulenceModel");


    // Constructors

        //- Construct from components
        incompressibleTwoPhase0TurbulenceModel
        (
            const volScalarField& rho,
            const volVectorField& U,
            const surfaceScalarField& alphaRhoPhi,
            const surfaceScalarField& phi,
            const word& propertiesName
        );


    //- Destructor
    virtual ~incompressibleTwoPhase0TurbulenceModel()
    {}


    // Member Functions

        //- Return the laminar dynamic viscosity
        virtual tmp<volScalarField> mu() const;

        //- Return the laminar dynamic viscosity on patch
        virtual tmp<scalarField> mu(const label patchi) const;

        //- Return the turbulence dynamic viscosity
        virtual tmp<volScalarField> mut() const;

        //- Return the turbulence dynamic viscosity on patch
        virtual tmp<scalarField> mut(const label patchi) const;

        //- Return the effective dynamic viscosity
        virtual tmp<volScalarField> muEff() const;

        //- Return the effective dynamic viscosity on patch
        virtual tmp<scalarField> muEff(const label patchi) const;

        //- Return the effective stress tensor including the laminar stress
        virtual tmp<volSymmTensorField> devReff() const = 0;

        //- Return the source term for the momentum equation
        virtual tmp<fvVectorMatrix> divDevReff(volVectorField& U) const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
