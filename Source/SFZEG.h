#ifndef SFZEG_h
#define SFZEG_h

#include "SFZRegion.h"


class SFZEG {
	public:
		SFZEG();

		void	startNote(
			const SFZEGParameters* parameters, float floatVelocity, float sampleRate,
			const SFZEGParameters* velMod = 0);
		void	nextSegment();
		void	noteOff();
		bool	isDone() { return segment == Done; }

		float       	level;
		float       	slope;
		unsigned int	samplesUntilNextSegment;

	protected:
		enum Segment {
			Delay, Attack, Hold, Decay, Sustain, Release, Done
			};
		Segment	segment;
		SFZEGParameters	parameters;
		float	sampleRate;

		void	startDelay();
		void	startAttack();
		void	startHold();
		void	startDecay();
		void	startSustain();
		void	startRelease();
	};


#endif 	// !SFZEG_h
