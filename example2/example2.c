
//data loss: (char)myinteger
//data modification: (char)myinteger

typedef struct s_home{
	int x,y,w,h;
} home;

typedef struct s_garage{
	home* house_ptr;
	int x,y,w,h;
} garage;

typedef struct s_dummy{
	int x,y;
} dummy_obj;


garage* MakeGarage(int ac, char** args);
dummy_obj* MakeDummy(int ac, char** args);
home* MakeHouse(int ac, char** args);

void * my_universal_return_type_method(int ac, char** args, char* tag){
	switch(get_type(tag, MY_TYPE_MAP, MY_TYPE_COUNT)){
	case 1: // make a house
		home* home = MakeHouse(ac, args);
		return (void*)home;
	case 2: // make a garage
		garage* house* = MakeGarage(ac, args);
		return (void*);
	default: // make a dummy object
		dummy_obj* dummy = MakeDummy(ac, args);
		return (void*)dummy;
	}
	return NULL; //GRAVE ERROR
}


void my_universal_free((void *)house, my_house_destructor);

garage* MakeGarage(int ac, char** args){
	// For i in args
	// parse pair
}

dummy_obj* MakeDummy(int ac, char** args){
	// For i in args
	// parse pair
}

home* MakeHouse(int ac, char** args){
	// For i in args
	// parse pair
}


home* get_home(char** blueprint, void* house_data){
	home* home = (home*)(my_universal_return_type_method(1, my_house_string, "home"));
}

home* get_garage(char** blueprint, void* house_data){
	home* home = (home*)(my_universal_return_type_method(1, my_house_string, "garage"));
}

home* get_dummy(char** blueprint, void* house_data){
	home* home = (home*)(my_universal_return_type_method(1, my_house_string, "dummy"));
}

int get_type(char* tag, char** type_map, int size){
	for(int i = 0; i<size; i++){
		if(strcmp(type_map[i], tag) == 0) return i; //Home
	}
	return -1;
}

int main(int ac, char** args){
	// Format
	// tag Argpair1 Argpair2 ...
	// 
}
