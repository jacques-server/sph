/*
 * Copyright (C) 2015 Wiky L
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.";
 */
#include "mod.h"
#include <stdio.h>

#include <stdlib.h>
#include <dlfcn.h>


/* 从指定文件载入模块，失败返回NULL */
JacModule *jac_module_load(const char *path) {
    void *handle = dlopen(path, RTLD_NOW|RTLD_NODELETE);
    if(!handle) {
        return NULL;
    }

    JacModule *mod = NULL;
    void *ptr=dlsym(handle, JACQUES_MODULE_STRING);
    if(!ptr) {
        goto CLOSE;
    }
    mod = *((JacModule**)ptr);
CLOSE:
    dlclose(handle);
    return mod;
}
