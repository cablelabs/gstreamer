/* GStreamer
 * Copyright (C) 2012 Olivier Crete <olivier.crete@collabora.com>
 *
 * gstdevice.c: Device discovery
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#ifndef __GST_DEVICE_H__
#define __GST_DEVICE_H__

typedef struct _GstDevice GstDevice;
typedef struct _GstDeviceClass GstDeviceClass;

#include <gst/gstelement.h>
#include <gst/gstcaps.h>


G_BEGIN_DECLS

typedef struct _GstDevicePrivate GstDevicePrivate;

#define GST_TYPE_DEVICE                 (gst_device_get_type())
#define GST_IS_DEVICE(obj)              (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GST_TYPE_DEVICE))
#define GST_IS_DEVICE_CLASS(klass)      (G_TYPE_CHECK_CLASS_TYPE ((klass), GST_TYPE_DEVICE))
#define GST_DEVICE_GET_CLASS(obj)       (G_TYPE_INSTANCE_GET_CLASS ((obj), GST_TYPE_DEVICE, GstDeviceClass))
#define GST_DEVICE(obj)                 (G_TYPE_CHECK_INSTANCE_CAST ((obj), GST_TYPE_DEVICE, GstDevice))
#define GST_DEVICE_CLASS(klass)         (G_TYPE_CHECK_CLASS_CAST ((klass), GST_TYPE_DEVICE, GstDeviceClass))
#define GST_DEVICE_CAST(obj)            ((GstDevice *)(obj))


struct _GstDevice {
  GstObject         parent;

  /*< private >*/
  GstDevicePrivate *priv;

  gpointer _gst_reserved[GST_PADDING];
};

struct _GstDeviceClass {
  GstObjectClass    parent_class;

  GstElement * (*create_element) (GstDevice * device, const gchar * name);
  gboolean (*reconfigure_element) (GstDevice * device, GstElement * element);

  /*< private >*/
  gpointer _gst_reserved[GST_PADDING];
};

GType        gst_device_get_type (void);

GstElement * gst_device_create_element (GstDevice * device, const gchar * name);

GstCaps *    gst_device_get_caps (GstDevice * device);
gchar *      gst_device_get_display_name (GstDevice * device);
gchar *      gst_device_get_klass (GstDevice * device);
gboolean     gst_device_reconfigure_element (GstDevice * device,
                                             GstElement * element);

gboolean      gst_device_has_classesv (GstDevice * device,
                                       gchar ** classes);

gboolean      gst_device_has_classes (GstDevice * device,
                                      const gchar * classes);


G_END_DECLS

#endif /* __GST_DEVICE_H__ */
