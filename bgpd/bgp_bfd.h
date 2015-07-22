/**
 * bgp_bfd.h: BGP BFD definitions and structures
 *
 * @copyright Copyright (C) 2015 Cumulus Networks, Inc.
 *
 * This file is part of GNU Zebra.
 *
 * GNU Zebra is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * GNU Zebra is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Zebra; see the file COPYING.  If not, write to the Free
 * Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#ifndef _QUAGGA_BGP_BFD_H
#define _QUAGGA_BGP_BFD_H

#define BGP_BFD_DEF_MIN_RX 300
#define BGP_BFD_DEF_MIN_TX 300
#define BGP_BFD_DEF_DETECT_MULT 3

#define BGP_BFD_FLAG_PARAM_CFG (1 << 0) /* parameters have been configured */
#define BGP_BFD_FLAG_BFD_REG   (1 << 1) /* Peer registered with BFD */

struct bgp_bfd_peer_info
{
  u_int16_t flags;
  u_int8_t  detect_mult;
  u_int32_t desired_min_tx;
  u_int32_t required_min_rx;
};

extern void
bgp_bfd_init(void);

extern void
bgp_bfd_peer_init(struct peer *peer);

extern void
bgp_bfd_peer_free(struct peer *peer);

extern void
bgp_bfd_peer_group2peer_copy(struct peer *conf, struct peer *peer);

extern void
bgp_bfd_register_peer (struct peer *peer);

extern void
bgp_bfd_deregister_peer (struct peer *peer);

extern void
bgp_bfd_update_peer (struct peer *peer);

extern void
bgp_bfd_peer_config_write(struct vty *vty, struct peer *peer, char *addr);

extern void
bgp_bfd_show_info(struct vty *vty, struct peer *peer);

#endif /* _QUAGGA_BGP_BFD_H */