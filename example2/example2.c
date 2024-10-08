my_house_struct house = (my_housestruct*)(my_universal_return_type_method(1, my_house_string, "my_house"));

my_universal_free((void *)house, my_house_destructor)

(int*)malloc(sizeof(char)*MAX_SIZE);

data loss: (char)myinteger
data modification: (char)myinteger

void * my_universal_return_type_method(int ac, char**, ...){
	switch(get_type(tag)){
	case 1: // make a house
		house* = MakeHouse();
		return (void*)house;
	break;
	case 2: // make a garage
	break;
	default: // make a dummy object
	break;
	}