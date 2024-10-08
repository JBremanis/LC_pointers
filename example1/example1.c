// Texture processing example of using a texture region
// Mentions of Preprocessor definitions and macros
//
// Usefull links
//
//include <SomeLegitTextureLibrary.h>
#include <stdlib.h>

struct my_scannning_window{

}

typedef struct my_bitmap{
    int** rgb_color_array;
    int width, height;
} my_bitmap;

typedef struct my_bitmap_region{
    my_bitmap* bitmap;
    int origin_x, origin_y;
    int width, height;
} my_bitmapregion;

typedef struct my_wallpaper_static{
    my_bitmap* bitmap_array;
    int width_rep;
    int height_rep;
} my_wallpaper_static;

typedef struct my_wallpaper_bitmap{
    my_bitmap* bitmap_wallpaper;
} my_wallpaper_texture;

typedef struct my_wallpaper_refrence_array{
    my_bitmap** bitmap_texture;
    int width_rep;
    int height_rep;
} my_wallpaper_reference;

typedef struct my_wallpaper_one_refrence{
    my_bitmap* bitmap_texture;
    int width_rep;
    int height_rep;
} my_wallpaper_reference;



void draw_bitmap(my_bitmap * bitmap){
    for(int i = 0; i < bitmap->height; i++)
        for(int j = 0; j < bitmap->width; j++)
            SLTL_write_to_display(1, bitmap->rgb_color_array[i][j], i, j);
}

void draw_bitmap_at(my_bitmap * bitmap, int origin_x, int origin_y){
    for(int i = 0; i < bitmap->height; i++)
        for(int j = 0; j < bitmap->width; j++)
            SLTL_write_pixel_to_display(1, bitmap->rgb_color_array[i][j], origin_x+i, origin_y+j);
}

void draw_bitmap_region(my_bitmap_region * texture_region){
    for(int i=0; i < texture_region->height; i++)
        for(int j = 0; j < texture_region->width; j++)
            SLTL_write_pixel_to_display(1, bitmap->rgb_color_array[i+texture_region->origin_x][j+origin_y], i, j);
}

void draw_bitmap_region_at(my_bitmap_region * texture_region, int origin_x, int origin_y){
    for(int i=0; i < texture_region->height; i++)
        for(int j = 0; j < texture_region->width; j++)
            SLTL_write_pixel_to_display(1, bitmap->rgb_color_array[i+texture_region->origin_x][j+origin_y], i, j);
}

void draw_wallpaper(my_wallpaper_static * bitmap){
    for(int i = 0; i< bitmap->height_rep; i++)
        for(int j = 0; j< bitmap->width_rep; j++)
            draw_bitmap(bitmap->bitmap_array[i][j]);
}

void draw_wallpaper_bitmap(my_wallpaper_texture * bitmap){
    draw_bitmap(bitmap->bitmap_wallpaper);
}

void draw_wallpaper_with_texture(my_wallpaper_reference * bitmap){
    for(int i=0; i< bitmap->height_rep; i++)
        for(int j = 0; j< bitmap->width_rep; j++)
            draw_bitmap_at(bitmap, bitmap->width_rep*j, bitmap->height_rep*i);
}

my_bitmap* malloc_bitmap(int texture_width, int texture_height){
    my_bitmap* new_bitmap = (my_bitmap*)malloc(sizeof(my_bitmap));
    new_bitmap->width = texture_width;
    new_bitmap->height = texture_height;
    new_bitmap->rgb_color_array = (int**)malloc(sizeof(unsigned int)*texture_width*texture_height);
}

my_bitmap* copy_bitmap(my_bitmap* source){
    my_bitmap* new_bitmap = (my_bitmap*)malloc(sizeof(my_bitmap));
    new_bitmap->width = texture_width;
    new_bitmap->height = texture_height;
    new_bitmap->rgb_color_array = (int**)malloc(sizeof(unsigned int)*texture_width*texture_height);
}

int free_bitmap(my_bitmap* trash){
    if(trash->rgb_color_array != NULL) free(trash->rgb_color_array);
    if(trash->width != NULL) free(trash->width);
    if(trash->height != NULL) free(trash->height);
    if(trash != NULL) free(trash);
    return 1; //can add error codes for all failed cases (if ptr isn't null), but lets not do it
}


int main(){
#define STATIC_ALLOC
#ifdef STATIC_ALLOC
// unsigned int my_bitmap[][] = SLTL_import_img_as_bitmap_array();
const int texture_width = 640;
const int texture_height = 480;
const int wallpaper_width = 12*texture_width;
const int wallpaper_height = 12*texture_height;
int** my_texture_bitmap = malloc_bitmap(texture_width, texture_height);
my_bitmap* my_wallpaper_bitmap = ;
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


}