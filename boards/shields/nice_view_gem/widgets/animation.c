#include <stdlib.h>
#include <zephyr/kernel.h>
#include "animation.h"

enum ART {
    REINA,
    KNIGHT,
    HORNET
};

LV_IMG_DECLARE(reinamomo);

LV_IMG_DECLARE(knight0);
LV_IMG_DECLARE(knight1);
LV_IMG_DECLARE(knight2);
LV_IMG_DECLARE(knight3);
LV_IMG_DECLARE(knight4);
LV_IMG_DECLARE(knight5);
LV_IMG_DECLARE(knight6);
LV_IMG_DECLARE(knight7);

LV_IMG_DECLARE(hornet0);
LV_IMG_DECLARE(hornet1);
LV_IMG_DECLARE(hornet2);
LV_IMG_DECLARE(hornet3);
LV_IMG_DECLARE(hornet4);
LV_IMG_DECLARE(hornet5);
LV_IMG_DECLARE(hornet6);
LV_IMG_DECLARE(hornet7);

const lv_img_dsc_t *anim_knight_imgs[] = {
    &knight0, &knight1, &knight2, &knight3,
    &knight4, &knight5, &knight6, &knight7,
};

const lv_img_dsc_t *anim_hornet_imgs[] = {
    &hornet0, &hornet1, &hornet2, &hornet3,
    &hornet4, &hornet5, &hornet6, &hornet7,
};

void draw_animation(lv_obj_t *canvas) {
#if IS_ENABLED(CONFIG_NICE_VIEW_GEM_ANIMATION)
    srand(k_uptime_get_32());
    enum ART asset = rand() % 3;

    switch (asset) {
        case REINA:
            lv_obj_t *art = lv_img_create(canvas);
            lv_img_set_src(art, &reinamomo);
        break;
        case KNIGHT:
            lv_obj_t *art = lv_animimg_create(canvas);
            lv_obj_center(art);
            lv_animimg_set_src(art, (const void **)anim_knight_imgs, 8);
            lv_animimg_set_duration(art, CONFIG_NICE_VIEW_GEM_ANIMATION_MS);
            lv_animimg_set_repeat_count(art, LV_ANIM_REPEAT_INFINITE);
            lv_animimg_start(art);
        break;
        case HORNET:
            lv_obj_t *art = lv_animimg_create(canvas);
            lv_obj_center(art);
            lv_animimg_set_src(art, (const void **)anim_hornet_imgs, 8);
            lv_animimg_set_duration(art, CONFIG_NICE_VIEW_GEM_ANIMATION_MS);
            lv_animimg_set_repeat_count(art, LV_ANIM_REPEAT_INFINITE);
            lv_animimg_start(art);
        break;
    }
#else
    lv_obj_t *art = lv_img_create(canvas);

    int length = sizeof(anim_knight_imgs) / sizeof(anim_knight_imgs[0]);
    srand(k_uptime_get_32());
    int random_index = rand() % length;

    lv_img_set_src(art, anim_knight_imgs[random_index]);
#endif

    lv_obj_align(art, LV_ALIGN_TOP_LEFT, 0, 0);
}