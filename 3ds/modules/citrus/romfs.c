#include <3ds.h>

#include "py/runtime.h"

#include "../init_helper.h"

#define METHOD_OBJ_N(__args, __n) \
    STATIC MP_DEFINE_CONST_FUN_OBJ_##__args(mod_citrus_romfs_##__n##_obj, mod_citrus_romfs_##__n)

#define LOCAL_METHOD(__n) \
    {MP_OBJ_NEW_QSTR(MP_QSTR_##__n), (mp_obj_t) &mod_citrus_romfs_##__n##_obj}

static int _mod_citrus_romfs_is_init = 0;

STATIC mp_obj_t mod_citrus_romfs_init(void) {
    INIT_ONCE(_mod_citrus_romfs_is_init);

    romfsInit();

    return mp_const_none;
}

mp_obj_t mod_citrus_romfs_exit(void) {
    EXIT_ONCE(_mod_citrus_romfs_is_init);

    romfsExit();

    return mp_const_none;
}

METHOD_OBJ_N(0, init);
METHOD_OBJ_N(0, exit);

STATIC const mp_rom_map_elem_t mp_module_citrus_romfs_globals_table[] = {
        // Package Info
        {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_romfs)},

        // Functions
        LOCAL_METHOD(init),
        LOCAL_METHOD(exit),
};

STATIC MP_DEFINE_CONST_DICT(mp_module_citrus_romfs_globals, mp_module_citrus_romfs_globals_table);

const mp_obj_module_t mp_module_citrus_romfs = {
        .base = {&mp_type_module},
        .name = MP_QSTR_romfs,
        .globals = (mp_obj_dict_t *) &mp_module_citrus_romfs_globals,
};