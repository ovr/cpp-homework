#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

struct Entity {
	string title;
	unsigned int id;
	string username;
};

#define FIRST_INIT 6

static int countEntityDoubleId[FIRST_INIT] = {0,0,0,0,0,0};

bool sortEntity( const Entity& entityA,  const Entity& entityB)
{	
	return countEntityDoubleId[entityA.id] > countEntityDoubleId[entityB.id];
}


void viewEntity( const Entity& entity )
{
   cout << "title: " << entity.title << endl << "id: " << entity.id << endl << "username: " << entity.username << endl << "==============" << endl;
}

int main(int argc, char *argv[])
{         
	vector<Entity> entitiesVector(FIRST_INIT);

	entitiesVector[0].title = "test 0";
	entitiesVector[0].id = 5;
	entitiesVector[0].username = "username 0";
	countEntityDoubleId[entitiesVector[0].id]++;
	
	entitiesVector[1].title = "test 1";
	entitiesVector[1].id = 1;
	entitiesVector[1].username = "username 1";
	countEntityDoubleId[entitiesVector[1].id]++;
	
	entitiesVector[2].title = "test 2";
	entitiesVector[2].id = 1;
	entitiesVector[2].username = "username 2";
	countEntityDoubleId[entitiesVector[2].id]++;
	
	entitiesVector[3].title = "test 3";
	entitiesVector[3].id = 3;
	entitiesVector[3].username = "username 3";
	countEntityDoubleId[entitiesVector[3].id]++;
	
	entitiesVector[4].title = "test 4";
	entitiesVector[4].id = 1;
	entitiesVector[4].username = "username 4";
	countEntityDoubleId[entitiesVector[4].id]++;
	
	entitiesVector[5].title = "test 5";
	entitiesVector[5].id = 5;
	entitiesVector[5].username = "username 5";
	countEntityDoubleId[entitiesVector[5].id]++;
	
	sort (entitiesVector.begin(), entitiesVector.end(), sortEntity); 
	
	for_each(entitiesVector.begin(), entitiesVector.end(), viewEntity);
	
	for(int i = 0; i < FIRST_INIT; i++) {
		cout << i << " = " << countEntityDoubleId[i] << endl;
	}

    return EXIT_SUCCESS;
}
