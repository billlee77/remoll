#ifndef __REMOLLGENERICDETECTORHIT_HH
#define __REMOLLGENERICDETECTORHIT_HH

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"

class remollGenericDetectorHit : public G4VHit {
    public:
	remollGenericDetectorHit(G4int, G4int);
	virtual ~remollGenericDetectorHit();

	remollGenericDetectorHit(const remollGenericDetectorHit &right);
	const remollGenericDetectorHit& operator=(const remollGenericDetectorHit &right);
	G4int operator==(const remollGenericDetectorHit &right) const;

	inline void *operator new(size_t);
	inline void operator delete(void *aHit);

    private:

    public:
	G4int fDetID;
	G4int fCopyID;

	// Position and momentum in lab coordinates
	G4ThreeVector f3X;
	G4ThreeVector f3P;
	// Total momentum, energy, mass
	G4double fP, fE, fM;
	// Origin
	G4ThreeVector f3V;
	// Geant4 track ID, particle type, and mother ID
	G4int    fTrID, fPID, fmTrID;
	// Process generator type
	G4int    fGen;

};


typedef G4THitsCollection<remollGenericDetectorHit> remollGenericDetectorHitCollection;

extern G4ThreadLocal G4Allocator<remollGenericDetectorHit>* remollGenericDetectorHitAllocator;

inline void* remollGenericDetectorHit::operator new(size_t){
  if (!remollGenericDetectorHitAllocator)
    remollGenericDetectorHitAllocator = new G4Allocator<remollGenericDetectorHit>;
  return (void *) remollGenericDetectorHitAllocator->MallocSingle();
}

inline void remollGenericDetectorHit::operator delete(void *aHit){
  remollGenericDetectorHitAllocator->FreeSingle( (remollGenericDetectorHit*) aHit);
}

#endif//__REMOLLGENERICDETECTORHIT_HH
