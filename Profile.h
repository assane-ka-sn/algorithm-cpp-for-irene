#include<iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstdlib>


class Profile
{

    //Function Members
    public:
      //Constructor
      Profile();
      //Destructor
      ~Profile();

      void initialistionMatrice();

      void nbreOccurencePositionParSequence();

      void poidsOccurencePositionParSequence();

      void afficher();

    //Data members
    private:
      char **_matrice;
      int **_nbreOcurrencePS;
      int **_poidsOcurrencePS;
      std::vector<std::string> _sequenceList;
      std::vector<std::string> _positionList;
      std::vector<char> _alphbet;
      int _nRows = 0;
      int _nCols = 0;
};


//Operator overloading for matrix operations!
