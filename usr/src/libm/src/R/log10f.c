/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#pragma ident	"@(#)log10f.c	1.11	06/01/23 SMI"

#pragma weak log10f = __log10f

#include "libm.h"

static const float zero = 0.0f, mone = -1.0f;

float
log10f(float x) {
	int	hx, ix;
	float	w;

	hx = *(int *)&x;
	ix = hx & ~0x80000000;
	if (ix > 0x7f800000)
		return (x * x);
	if (ix == 0x7f800000)
		return (x + x * x);
	if (ix == 0) {
		w = mone;
		return (w / zero);
	}
	if (hx < 0) {
		w = zero;
		return (w / zero);
	}
	return ((float)log10((double)x));
}
