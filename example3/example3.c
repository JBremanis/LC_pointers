
#include <stdlib.h>
#include <stdio.h> 
typedef int (*func_ptr)();

int close();
int minimize();
int enlarge();


typedef struct s_button{
	char arg;
	unsigned char clicked;
	func_ptr on_click;
} my_arg;

unsigned char is_clicked(my_arg* arg){
	return arg->clicked;
}

int close(){
	printf("Close\n");
	return 0;
}

int minimize(){
	printf("Minimize\n");
	return 0;
}

int enlarge(){
	printf("Enlarge\n");
	return 0;
}

int main(int ac, char** argv){
	/*
	my_arg close_arg = {'c', 0};
	my_arg minimize_arg = {'m', 0};
	my_arg enlarge_arg = {'e', 0};
	*/
	my_arg close_arg = {'c', 0, close};
    my_arg minimize_arg = {'m', 0, minimize};
    my_arg enlarge_arg = {'e', 0, enlarge};

    my_arg** arguments = (my_arg**)malloc(sizeof(my_arg*)*3);
	arguments[0] = &close_arg;
	arguments[1] = &minimize_arg;
	arguments[2] = &enlarge_arg;

	for(int i = 1; i < ac; i++){
		for(int j = 0; j < 3; j++){
			if(argv[i][0] == arguments[j]->arg) arguments[j]->clicked = 1;
		}
	}

    /*// no function pointers
    for(int i = 0; i < 3; i++){
		my_arg* b = arguments[i];
	    if(is_clicked(b)){
		    switch(b->arg){
			    case 'c':
				    close();
			    break;
			    case 'm':
				    minimize();
			    break;
			    case 'e':
				    enlarge();
			    break;
		    }
	    }
    }*/
	
    
    for(int i = 0; i < 3; i++){
		my_arg* b = arguments[i];
	    if(is_clicked(b)) (b->on_click)();
    }

	free(arguments);
}




