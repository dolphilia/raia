//
// Created by dolphilia on 2024/01/08.
//

#include "sk_font_metrics.h"

extern "C" {

void SkFontMetrics_delete(SkFontMetrics *font_metrics) {
    delete font_metrics;
}

bool SkFontMetrics_hasUnderlineThickness(SkFontMetrics *font_metrics, SkScalar *thickness) {
    return font_metrics->hasUnderlineThickness(thickness);
}

bool SkFontMetrics_hasUnderlinePosition(SkFontMetrics *font_metrics, SkScalar *position) {
    return font_metrics->hasUnderlinePosition(position);
}

bool SkFontMetrics_hasStrikeoutThickness(SkFontMetrics *font_metrics, SkScalar *thickness) {
    return font_metrics->hasStrikeoutThickness(thickness);
}

bool SkFontMetrics_hasStrikeoutPosition(SkFontMetrics *font_metrics, SkScalar *position) {
    return font_metrics->hasStrikeoutPosition(position);
}

bool SkFontMetrics_hasBounds(SkFontMetrics *font_metrics) {
    return font_metrics->hasBounds();
}

}