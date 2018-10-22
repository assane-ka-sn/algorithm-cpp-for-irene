#include<iostream>
#include <vector>
#include <string>
#include <stdlib.h>

#include "Profile.h"

using namespace std;

int main()
{
	Profile _profile = Profile();
	_profile.initialistionMatrice();
	_profile.nbreOccurencePositionParSequence();

	_profile.poidsOccurencePositionParSequence();

    _profile.afficher();

	return 0;
}
