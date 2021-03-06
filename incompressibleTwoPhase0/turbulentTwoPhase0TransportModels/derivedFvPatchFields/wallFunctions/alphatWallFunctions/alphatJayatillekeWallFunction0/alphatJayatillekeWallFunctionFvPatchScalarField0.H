/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2016 OpenFOAM Foundation
     \\/     M anipulation  | Copyright (C) 2017 OpenCFD Ltd
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
    Foam::incompressible::alphatJayatillekeWallFunctionFvPatchScalarField0

Group
    grpIcoWallFunctions

Description
    This boundary condition provides a kinematic turbulent thermal conductivity
    for using wall functions, using the Jayatilleke 'P' function.

Usage
    \table
        Property     | Description             | Required    | Default value
        Prt          | turbulent Prandtl number | no         | 0.85
        kappa        | Von Karman constant     | no          | 0.41
        E            | model coefficient       | no          | 9.8
    \endtable

    Example of the boundary condition specification:
    \verbatim
    <patchName>
    {
        type            alphatJayatillekeWallFunction;
    }
    \endverbatim

Note
    The units of kinematic turbulent thermal conductivity are [m2/s]

See also
    Foam::fixedValueFvPatchField

SourceFiles
    alphatJayatillekeWallFunctionFvPatchScalarField0.C

\*---------------------------------------------------------------------------*/

#ifndef alphatJayatillekeWallFunctionFvPatchScalarField0_H
#define alphatJayatillekeWallFunctionFvPatchScalarField0_H

#include "fixedValueFvPatchFields.H"
#include "turbulenceModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace incompressibleTwoPhase0
{

/*---------------------------------------------------------------------------*\
       Class alphatJayatillekeWallFunctionFvPatchScalarField0 Declaration
\*---------------------------------------------------------------------------*/

class alphatJayatillekeWallFunctionFvPatchScalarField0
:
    public fixedValueFvPatchScalarField
{
protected:

    // Protected data

        //- Turbulent Prandtl number
        scalar Prt_;

        //- Von Karman constant
        scalar kappa_;

        //- E coefficient
        scalar E_;


        // Solution parameters

            static scalar tolerance_;
            static label maxIters_;


    // Protected member functions

        //- Check the type of the patch
        virtual void checkType();

        //- Return the patch y+
        tmp<scalarField> yPlus(const turbulenceModel& turbModel) const;

        //- `P' function
        scalar Psmooth(const scalar Prat) const;

        //- Calculate y+ at the edge of the thermal laminar sublayer
        scalar yPlusTherm
        (
            const scalar P,
            const scalar Prat
        ) const;


public:

    //- Runtime type information
    TypeName("alphatJayatillekeWallFunction0");


    // Constructors

        //- Construct from patch and internal field
        alphatJayatillekeWallFunctionFvPatchScalarField0
        (
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&
        );

        //- Construct from patch, internal field and dictionary
        alphatJayatillekeWallFunctionFvPatchScalarField0
        (
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&,
            const dictionary&
        );

        //- Construct by mapping given
        //  alphatJayatillekeWallFunctionFvPatchScalarField0
        //  onto a new patch
        alphatJayatillekeWallFunctionFvPatchScalarField0
        (
            const alphatJayatillekeWallFunctionFvPatchScalarField0&,
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&,
            const fvPatchFieldMapper&
        );

        //- Construct as copy
        alphatJayatillekeWallFunctionFvPatchScalarField0
        (
            const alphatJayatillekeWallFunctionFvPatchScalarField0&
        );

        //- Construct and return a clone
        virtual tmp<fvPatchScalarField> clone() const
        {
            return tmp<fvPatchScalarField>
            (
                new alphatJayatillekeWallFunctionFvPatchScalarField0(*this)
            );
        }

        //- Construct as copy setting internal field reference
        alphatJayatillekeWallFunctionFvPatchScalarField0
        (
            const alphatJayatillekeWallFunctionFvPatchScalarField0&,
            const DimensionedField<scalar, volMesh>&
        );

        //- Construct and return a clone setting internal field reference
        virtual tmp<fvPatchScalarField> clone
        (
            const DimensionedField<scalar, volMesh>& iF
        ) const
        {
            return tmp<fvPatchScalarField>
            (
                new alphatJayatillekeWallFunctionFvPatchScalarField0(*this, iF)
            );
        }


    // Member functions

        // Evaluation functions

            //- Update the coefficients associated with the patch field
            virtual void updateCoeffs();


        // I-O

            //- Write
            virtual void write(Ostream&) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace incompressibleTwoPhase0
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
