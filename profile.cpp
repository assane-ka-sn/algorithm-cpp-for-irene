#include<iostream>
#include "Profile.h"

using namespace std;

Profile::Profile()
{

}

Profile::~Profile()
{
  for (int i=0; i < _nRows; i++)
    delete[] _matrice[i];
  delete[] _matrice;

  for (int i=0; i < _nCols; i++)
    delete[] _nbreOcurrencePS[i];
  delete[] _nbreOcurrencePS;

  for (int i=0; i < _nCols; i++)
    delete[] _poidsOcurrencePS[i];
  delete[] _poidsOcurrencePS;
}


void Profile::initialistionMatrice()
{
	ifstream fichier("trainbis.txt");
	string ligne;
	int compteur = 1;
    if(fichier){
      while(getline(fichier, ligne)){
            if(compteur%2==0){
                _nRows++;
                _sequenceList.push_back(ligne);
                _nCols = ligne.size();
            }
            compteur++;
      }
    }
    /* Allocation dynamique */
    _matrice = new char* [ _nRows ];
    for (int i=0; i < _nRows; i++)
        _matrice[i] = new char[ _nCols ];

    /* Initialisation matrice */
    for (int i=0; i < _nRows; i++)
        for (int j=0; j < _nCols; j++)
            _matrice[i][j] = _sequenceList[i][j];
}

void Profile::nbreOccurencePositionParSequence()
{
	/* Initialisation position */
    for (int j=0; j < _nCols; j++){
        string position = "";
        for (int i=0; i < _nRows; i++){
            position += _matrice[i][j];
            if(std::count(_alphbet.begin(),_alphbet.end(),_matrice[i][j])){
                continue;
            }else _alphbet.push_back(_matrice[i][j]);
        }
        _positionList.push_back(position);
    }
    std::sort (_alphbet.begin(), _alphbet.end());

    /* Allocation dynamique */
    _nbreOcurrencePS = new int* [ _nCols ];
    for (int i=0; i < _nCols; i++)
        _nbreOcurrencePS[i] = new int[ _alphbet.size() ];

    /* Initialisation occurenceposition */
    for (int i=0; i < _nCols; i++)
        for (int j=0; j < _alphbet.size(); j++)
            _nbreOcurrencePS[i][j] = count(_positionList[i].begin(),_positionList[i].end(),_alphbet[j]);

}

void Profile::poidsOccurencePositionParSequence()
{
	/* Allocation dynamique */
    _poidsOcurrencePS = new int* [ _nCols ];
    for (int i=0; i < _nCols; i++)
        _poidsOcurrencePS[i] = new int[ _alphbet.size() ];

    /* Initialisation poidsoccurence */
    for (int i=0; i < _nCols; i++)
        for (int j=0; j < _alphbet.size(); j++)
            _poidsOcurrencePS[i][j] = _nbreOcurrencePS[i][j]+1;

}

void Profile::afficher()
{
    /* Affichage matrice initiale*/
    for (int i=0; i < _nRows; i++) {
        for (int j=0; j < _nCols; j++) cout << _matrice[i][j] << " ";
        cout << endl;
    }

    cout << endl;

    /* affichage _positionList alphabet et nbreOccurenceposition */
    for (int i=0; i < _alphbet.size(); i++){
        cout << _alphbet[i];
        for (int j=0; j < _nCols; j++)
            cout << "\t" << _nbreOcurrencePS[j][i] ;
        cout << endl;
    }

    cout << endl;

    /* affichage _positionList alphabet et poidsOccurenceposition */
    for (int i=0; i < _alphbet.size(); i++){
        cout << _alphbet[i];
        for (int j=0; j < _nCols; j++)
            cout << "\t" << _poidsOcurrencePS[j][i] << "/" << (_alphbet.size()+_nRows) ;
        cout << endl;
    }
}
