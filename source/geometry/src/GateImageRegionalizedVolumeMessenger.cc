/*----------------------
   Copyright (C): OpenGATE Collaboration

This software is distributed under the terms
of the GNU Lesser General  Public Licence (LGPL)
See LICENSE.md for further details
----------------------*/


/*! \file
  \brief Implementation of GateImageRegionalizedVolumeMessenger
 */

#include "GateImageRegionalizedVolumeMessenger.hh"
#include "GateImageRegionalizedVolume.hh"
#include "G4UIcommand.hh"

//====================================================================
GateImageRegionalizedVolumeMessenger::GateImageRegionalizedVolumeMessenger(GateImageRegionalizedVolume* volume)
  :
  GateVImageVolumeMessenger(volume),
  pVolume(volume)
{

  GateMessage("Volume",5,"GateImageRegionalizedVolumeMessenger()\n");

  G4String n = GetDirectoryName() +"geometry/distanceMap";
  pDistanceMapNameCmd = new G4UIcmdWithAString(n,this);
  pDistanceMapNameCmd->SetGuidance("Sets the name of the distance map file");
}
//====================================================================


//====================================================================
GateImageRegionalizedVolumeMessenger::~GateImageRegionalizedVolumeMessenger()
{
  GateMessage("Volume",5,"~GateImageRegionalizedVolumeMessenger()\n");
  delete  pDistanceMapNameCmd;
}
//====================================================================


//====================================================================
void GateImageRegionalizedVolumeMessenger::SetNewValue(G4UIcommand* command,
								   G4String newValue)
{
  ////GateMessage("Volume",5,"GateImageRegionalizedVolumeMessenger::SetNewValue "
	  //    << command->GetCommandPath()
	  //    << " newValue=" << newValue << Gateendl);

  if (command == pDistanceMapNameCmd) {
    pVolume->SetDistanceMapFilename(newValue);
  }
  else {
    GateVImageVolumeMessenger::SetNewValue(command,newValue);
  }
}

//====================================================================
