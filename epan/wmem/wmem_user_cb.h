/* wmem_user_cb.h
 * Definitions for the Wireshark Memory Manager User Callbacks
 * Copyright 2012, Evan Huus <eapache@gmail.com>
 *
 * $Id$
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __WMEM_USER_CB_H__
#define __WMEM_USER_CB_H__

#include <glib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** @addtogroup wmem
 *  @{
 *    @defgroup wmem-user-cb User Callbacks
 *
 *    User callbacks.
 *
 *    @{
 */

/** Function signature for registered user callbacks.
 *
 * @param allocator The allocator that triggered this callback.
 * @param final Whether this is was triggered due to the allocator being
 *              destroyed (TRUE) or simply a call to wmem_free_all() (FALSE).
 * @param user_data Whatever user_data was originally passed to the call to
 *              wmem_register_cleanup_callback().
 */
typedef void (*wmem_user_cb_t) (wmem_allocator_t *, gboolean, void *);

/** Register a callback function with the given allocator pool.
 *
 * @param allocator The allocator with which to register the callback.
 * @param recurring If this is FALSE then the callback is called exactly once.
 *                  If this is TRUE then the callback is called every time
 *                  wmem_free_all() is called on the allocator, and one last
 *                  time when wmem_destroy_allocator() is called on it.
 * @param callback  The function to be called as the callback.
 * @param user_data An arbitrary data pointer that is passed to the callback as
 *                  a way to specify extra parameters or store extra data. Note
 *                  that this pointer is not freed when a callback is finished,
 *                  you have to do that yourself in the callback, or just
 *                  allocate it in the appropriate wmem pool.
 */
WS_DLL_PUBLIC
void
wmem_register_cleanup_callback(wmem_allocator_t *allocator, gboolean recurring,
        wmem_user_cb_t callback, void *user_data);

/**   @}
 *  @} */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __WMEM_USER_CB_H__ */

/*
 * Editor modelines  -  http://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 4
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * vi: set shiftwidth=4 tabstop=8 expandtab:
 * :indentSize=4:tabSize=8:noTabs=true:
 */
