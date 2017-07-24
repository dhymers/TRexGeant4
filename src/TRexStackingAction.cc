#include "TRexStackingAction.hh"

#include "G4SystemOfUnits.hh"
#include "G4EventManager.hh"
#include "G4Event.hh"
#include "G4IonTable.hh"

TRexStackingAction::TRexStackingAction(){
	particleTable = G4ParticleTable::GetParticleTable();
	
	electronDef = nullptr;
	deuteronDef = nullptr;
	
	//out.open("electrons.dat", std::ios::app | std::ios::out);
}

TRexStackingAction::~TRexStackingAction()
{
    //out.close();
}

G4ClassificationOfNewTrack TRexStackingAction::ClassifyNewTrack(const G4Track* track){
	if (electronDef == nullptr){
		electronDef = particleTable->FindParticle("e-");
	}
	if (deuteronDef == nullptr){
	    deuteronDef = particleTable->FindParticle("deuteron");
	}
	
    G4ClassificationOfNewTrack classification;
    
    classification = fUrgent;
    
    //do not simulate electrons, to speed up simulation
    if(track->GetParticleDefinition() == electronDef){
        classification = fKill;
        //out << track->GetMomentumDirection().getTheta() << ", "
        //    << track->GetKineticEnergy() / CLHEP::keV
        //    << std::endl;
        
    }
    /*else if (track->GetParticleDefinition() == deuteronDef){
        G4cout  << "**********" << G4endl
                << "TrackID: " << track->GetTrackID() << G4endl
                << "ParentID: " << track->GetParentID() << G4endl
                << "Kinetic Energy (keV): " << track->GetKineticEnergy()/CLHEP::keV << G4endl
                << "Theta (deg): " << track->GetMomentumDirection().theta()/CLHEP::degree << G4endl
                << "x (mm): " << track->GetPosition().x()/CLHEP::mm << G4endl
                << "y (mm): " << track->GetPosition().y()/CLHEP::mm << G4endl
                << "z (mm): " << track->GetPosition().z()/CLHEP::mm << G4endl
                << "time (ns): " << track->GetGlobalTime()/CLHEP::ns << G4endl
                << "**********" << G4endl;
    }*/
    
    return classification;
}

void TRexStackingAction::NewStage()
{}

void TRexStackingAction::PrepareNewEvent()
{}

