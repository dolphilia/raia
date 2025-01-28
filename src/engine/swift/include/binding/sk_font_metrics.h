//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FONT_METRICS_H
#define RAIA_SKIA_SK_FONT_METRICS_H

#ifdef __cplusplus
extern "C" {
#endif

void SkFontMetrics_delete(void *font_metrics); // (SkFontMetrics *font_metrics)
bool SkFontMetrics_hasUnderlineThickness(void *font_metrics, void *thickness); // (SkFontMetrics *font_metrics, SkScalar *thickness) -> bool
bool SkFontMetrics_hasUnderlinePosition(void *font_metrics, void *position); // (SkFontMetrics *font_metrics, SkScalar *position) -> bool
bool SkFontMetrics_hasStrikeoutThickness(void *font_metrics, void *thickness); // (SkFontMetrics *font_metrics, SkScalar *thickness) -> bool
bool SkFontMetrics_hasStrikeoutPosition(void *font_metrics, void *position); // (SkFontMetrics *font_metrics, SkScalar *position) -> bool
bool SkFontMetrics_hasBounds(void *font_metrics); // (SkFontMetrics *font_metrics) -> bool

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_FONT_METRICS_H
