//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FONT_METRICS_H
#define RAIA_SKIA_SK_FONT_METRICS_H

#include "include/core/SkFontMetrics.h"

extern "C" {
void SkFontMetrics_delete(SkFontMetrics *font_metrics);
bool SkFontMetrics_hasUnderlineThickness(SkFontMetrics *font_metrics, SkScalar *thickness);
bool SkFontMetrics_hasUnderlinePosition(SkFontMetrics *font_metrics, SkScalar *position);
bool SkFontMetrics_hasStrikeoutThickness(SkFontMetrics *font_metrics, SkScalar *thickness);
bool SkFontMetrics_hasStrikeoutPosition(SkFontMetrics *font_metrics, SkScalar *position);
bool SkFontMetrics_hasBounds(SkFontMetrics *font_metrics);
}

#endif //RAIA_SKIA_SK_FONT_METRICS_H
