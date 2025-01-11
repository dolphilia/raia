//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FONT_METRICS_H
#define RAIA_SKIA_SK_FONT_METRICS_H

#include "include/core/SkFontMetrics.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkFontMetrics_delete(SkFontMetrics *font_metrics);
RAIA_API bool SkFontMetrics_hasUnderlineThickness(SkFontMetrics *font_metrics, SkScalar *thickness);
RAIA_API bool SkFontMetrics_hasUnderlinePosition(SkFontMetrics *font_metrics, SkScalar *position);
RAIA_API bool SkFontMetrics_hasStrikeoutThickness(SkFontMetrics *font_metrics, SkScalar *thickness);
RAIA_API bool SkFontMetrics_hasStrikeoutPosition(SkFontMetrics *font_metrics, SkScalar *position);
RAIA_API bool SkFontMetrics_hasBounds(SkFontMetrics *font_metrics);
}

#endif //RAIA_SKIA_SK_FONT_METRICS_H
