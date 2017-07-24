#ifndef TRexStackingAction_h
#define TRexStackingAction_h 1

#include "G4ClassificationOfNewTrack.hh"
#include "G4UserStackingAction.hh"
#include "G4ParticleTable.hh"
#include "G4Track.hh"
#include "G4ParticleDefinition.hh"
#include <iostream>

class TRexStackingAction : public G4UserStackingAction{
    public:
        TRexStackingAction();
        ~TRexStackingAction();
        
        virtual G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track*);
        virtual void NewStage();
        virtual void PrepareNewEvent();
        
    private:
        G4ParticleDefinition* electronDef;
        G4ParticleDefinition* deuteronDef;
        
        G4ParticleTable* particleTable;
        std::ofstream out;
};

#endif
