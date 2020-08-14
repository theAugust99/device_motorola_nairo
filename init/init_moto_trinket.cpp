/*
   Copyright (C) 2017-2018 The Android Open Source Project
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <android-base/properties.h>
#include <android-base/logging.h>
#include "property_service.h"
#include <sys/resource.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

namespace android {
namespace init {

using android::base::GetProperty;
using android::init::property_set;

void property_override(char const prop[], char const value[], bool add = true)
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
    __system_property_update(pi, value, strlen(value));
    else if (add)
    __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties() {
    std::string device = GetProperty("ro.boot.device", "");
    if (device == "sofia") {
        property_set("ro.build.product", "moto g power");
        property_set("ro.display.series", "moto g power");
        property_override("ro.product.model", "moto g power");
    } else if (device == "sofiar") {
        property_set("ro.build.product", "moto g(8) power");
        property_set("ro.display.series", "moto g(8) power");
        property_override("ro.product.model", "moto g(8) power");
    } else if (device == "sofiap") {
        property_set("ro.build.product", "moto g stylus");
        property_set("ro.display.series", "moto g stylus");
        property_override("ro.product.model", "moto g stylus");
    } else if (device == "sofiap_ao" || device == "sofiap_sprout") {
        property_set("ro.build.product", "moto g pro");
        property_set("ro.display.series", "moto g pro");
        property_override("ro.product.model", "moto g pro");
    } else if (device == "rav") {
        property_set("ro.build.product", "moto g(8)");
        property_set("ro.display.series", "moto g(8)");
        property_override("ro.product.model", "moto g(8)");
    } else if (device == "rav_t") {
        property_set("ro.build.product", "moto g fast");
        property_set("ro.display.series", "moto g fast");
        property_override("ro.product.model", "moto g fast");
    }
}

}  // namespace init
}  // namespace android
