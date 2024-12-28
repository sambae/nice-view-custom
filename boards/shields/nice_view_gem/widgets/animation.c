#include <stdlib.h>
#include <zephyr/kernel.h>
#include "animation.h"

LV_IMG_DECLARE(knight0);
LV_IMG_DECLARE(knight1);
LV_IMG_DECLARE(knight2);
LV_IMG_DECLARE(knight3);
LV_IMG_DECLARE(knight4);
LV_IMG_DECLARE(knight5);
LV_IMG_DECLARE(knight6);
LV_IMG_DECLARE(knight7);

const lv_img_dsc_t *anim_imgs[] = {
    &knight0, &knight1, &knight2, &knight3,
    &knight4, &knight5, &knight6, &knight7,
};

void draw_animation(lv_obj_t *canvas) {
#if IS_ENABLED(CONFIG_NICE_VIEW_GEM_ANIMATION)
    lv_obj_t *art = lv_animimg_create(canvas);
    lv_obj_center(art);

    lv_animimg_set_src(art, (const void **)anim_imgs, 8);
    lv_animimg_set_duration(art, CONFIG_NICE_VIEW_GEM_ANIMATION_MS);
    lv_animimg_set_repeat_count(art, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(art);
#else
    lv_obj_t *art = lv_img_create(canvas);

    int length = sizeof(anim_imgs) / sizeof(anim_imgs[0]);
    srand(k_uptime_get_32());
    int random_index = rand() % length;

    lv_img_set_src(art, anim_imgs[random_index]);
#endif

    lv_obj_align(art, LV_ALIGN_TOP_LEFT, 0, 0);
}