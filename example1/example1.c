// Texture processing example of using a texture region
// Mentions of Preprocessor definitions and macros
//
// Usefull links
// ANSI characters  https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
//include <SomeLegitTextureLibrary.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_my_bitmap{
    int** rgb_color_array;
    int width;
    int height;
} my_bitmap;

typedef struct s_my_bitmap_region{
    my_bitmap* bitmap;
    int origin_x, origin_y;
    int width, height;
} my_bitmap_region;

typedef struct s_my_wallpaper_static{
    my_bitmap* bitmap_array;
    int width_rep;
    int height_rep;
} my_wallpaper_static;

typedef struct s_my_wallpaper_bitmap{
    my_bitmap* bitmap_wallpaper;
} my_wallpaper_texture;

typedef struct s_my_wallpaper_refrence_array{
    my_bitmap** bitmap_texture;
    int width_rep;
    int height_rep;
} my_wallpaper_reference_array;

typedef struct s_my_wallpaper_one_refrence{
    my_bitmap* bitmap_texture;
    int width_rep;
    int height_rep;
} my_wallpaper_reference;

void SLTL_import_img_as_bitmap_array(my_bitmap* bitmap){

}

void SLTL_write_pixel_to_display(unsigned int color, int offset_x, int offset_y){
     //Move cursor
    printf("\033[s");
    printf("\033[%d;%dH", offset_y, offset_x); //Move cursor
    //printf("\033[38;2;%d;%d;%dm \f", color/256/256, (color/256)%256, color%256); //set color
    printf("\033[48;2;%d;%d;%dm ", color/256/256, (color/256)%256, color%256); //set color
    printf("\n");
    printf("\033[u");
    
    // or \\033[<L>;<C>f
    //print("\\033[s                           - Save cursor position")
    //print("\\033[u                           - Restore cursor position\n")
    //print("\\033[K                           - Erase to end of line")
    //printf("o\f");
}

void draw_bitmap(my_bitmap * bitmap){
    for(int i = 0; i < bitmap->height; i++){
        for(int j = 0; j < bitmap->width; j++){
            //SLTL_write_to_display(1, bitmap->rgb_color_array[i][j], i, j);
            printf(" %d ", bitmap->rgb_color_array[i][j]);
        }
        printf("\n");
    }
}

void draw_bitmap_at(my_bitmap * bitmap, int origin_x, int origin_y){
    for(int i = 0; i < bitmap->height; i++){
        for(int j = 0; j < bitmap->width; j++){
            //SLTL_write_pixel_to_display(1, bitmap->rgb_color_array[i][j], origin_x+i, origin_y+j);
            printf("\e[10C%s\n", "XYZ");
        }
    }
}

void draw_bitmap_region(my_bitmap_region * texture_region){
    for(int i=0; i < texture_region->height; i++)
        for(int j = 0; j < texture_region->width; j++)
            SLTL_write_pixel_to_display(texture_region->bitmap->rgb_color_array[i+texture_region->origin_x][j+texture_region->origin_y], i, j);
}

void draw_bitmap_region_at(my_bitmap_region * texture_region, int origin_x, int origin_y){
    for(int i=0; i < texture_region->height; i++)
        for(int j = 0; j < texture_region->width; j++)
            SLTL_write_pixel_to_display(texture_region->bitmap->rgb_color_array[i+texture_region->origin_x][j+origin_y], i, j);
}

void draw_wallpaper(my_wallpaper_static * bitmap){
    for(int i = 0; i< bitmap->height_rep; i++){
        for(int j = 0; j< bitmap->width_rep; j++){
            int offset_x = bitmap->bitmap_array[i*bitmap->width_rep+j].width*j;
            int offset_y =  bitmap->bitmap_array[i*bitmap->width_rep+j].height*i;
            draw_bitmap_at((bitmap->bitmap_array+i*bitmap->width_rep+j), offset_x, offset_y);
        }
    }
}

void draw_wallpaper_bitmap(my_wallpaper_texture * bitmap){
    draw_bitmap(bitmap->bitmap_wallpaper);
}

void draw_wallpaper_with_texture(my_wallpaper_reference * bitmap){
    for(int i=0; i< bitmap->height_rep; i++)
        for(int j = 0; j< bitmap->width_rep; j++)
            draw_bitmap_at(bitmap->bitmap_texture, bitmap->width_rep*j, bitmap->height_rep*i);
}

my_bitmap* malloc_bitmap(int texture_width, int texture_height){
    my_bitmap* new_bitmap = (my_bitmap*)malloc(sizeof(my_bitmap));
    new_bitmap->width = texture_width;
    new_bitmap->height = texture_height;
    new_bitmap->rgb_color_array = (int**)malloc(sizeof(unsigned int)*texture_width*texture_height);
    return new_bitmap;
}

my_bitmap* copy_bitmap(my_bitmap* source){
    my_bitmap* new_bitmap = (my_bitmap*)malloc(sizeof(my_bitmap));
    new_bitmap->width = source->width;
    new_bitmap->height = source->height;
    new_bitmap->rgb_color_array = (int**)malloc(sizeof(unsigned int)*source->width*source->height);
    for(int i=0; i< source->height; i++)
        for(int j = 0; j< source->width; j++)
            new_bitmap->rgb_color_array[j][i] = source->rgb_color_array[j][i];
    return new_bitmap;
}

int free_bitmap(my_bitmap* trash){
    if(trash->rgb_color_array != NULL) free(trash->rgb_color_array);
    if(trash != NULL) free(trash);
    return 1; //can add error codes for all failed cases (if ptr isn't null), but lets not do it
}

my_wallpaper_static* malloc_wallpaper(my_bitmap* texture, int texture_width_rep, int texture_height_rep){
    my_wallpaper_static* new_wp = (my_wallpaper_static*)malloc(sizeof(my_bitmap));
    new_wp->width_rep = texture_width_rep;
    new_wp->height_rep = texture_height_rep;
    new_wp->bitmap_array = (my_bitmap*)malloc(sizeof(my_bitmap)*texture_width_rep*texture_height_rep);
    for(int i = 0; i < texture_height_rep; i++){
        for(int j = 0; j < texture_width_rep; j++){
            my_bitmap* assign_to = (new_wp->bitmap_array+(i*texture_width_rep+j));
            assign_to = copy_bitmap(texture);
        }
    }
    return new_wp;
}

int free_wallpaper(my_wallpaper_static* trash){
    for(int i = 0; i < trash->height_rep; i++){
        for(int j = 0; j < trash->width_rep; j++){
            free_bitmap(((trash->bitmap_array)+(i*trash->width_rep+j)));
        }
    }
    return 1; //can add error codes for all failed cases (if ptr isn't null), but lets not do it
}


int main(){
#define STATIC_ALLOC
#ifdef STATIC_ALLOC

const int texture_width = 640;
const int texture_height = 480;
const int wallpaper_width = 12*texture_width;
const int wallpaper_height = 12*texture_height;
my_bitmap* my_texture_bitmap = malloc_bitmap(texture_width, texture_height);
SLTL_import_img_as_bitmap_array(my_texture_bitmap);
SLTL_import_img_as_bitmap_array(my_bitmap);
my_wallpaper_static* my_wallpaper = malloc_wallpaper();
draw_bitmap()
//SLTL_import_img_as_bitmap_array();
char dump;
while(true){
    int r = read(1, &dump, 1);
}
#elif //Using pointer as reference to texture
// unsigned int my_bitmap[][] = SLTL_import_img_as_bitmap_array();
const int texture_width = 640;
const int texture_height = 480;
int** my_bitmap = (int**)malloc(sizeof(unsigned int)*texture_width*texture_height);
int
#endif
/*
printf("\033[2J\n");
for(int i = 1; i < 10; i++){
    for(int j = 1; j < 10; j++){
        SLTL_write_pixel_to_display(i*10*0xFF00+j*10, j, i);
    }
}
printf("\n");
*/
char dump;
while(1){
    int r = read(1, &dump, 1);
}

}