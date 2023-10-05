/*
    Copyright 2015-2020 Clément Gallet <clement.gallet@ens-lyon.org>

    This file is part of libTAS.

    libTAS is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libTAS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libTAS.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "socketwrappers.h"
#include "logging.h"
#include "global.h"

#include <sys/socket.h>
#include <errno.h>

namespace libtas {

DEFINE_ORIG_POINTER(socket)

/* Override */ int socket (int domain, int type, int protocol) __THROW
{
    DEBUGLOGCALL(LCF_SOCKET);

    /* Deny internet access */
    if (domain == AF_INET || domain == AF_INET6) {
        if (!(Global::shared_config.debug_state & SharedConfig::DEBUG_NATIVE_INET)) {
            errno = EACCES;
            return -1;
        }
    }

    LINK_NAMESPACE_GLOBAL(socket);
    return orig::socket(domain, type, protocol);
}

}