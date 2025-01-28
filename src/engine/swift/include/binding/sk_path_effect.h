//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_PATH_EFFECT_H
#define RAIA_SKIA_SK_PATH_EFFECT_H

#ifdef __cplusplus
extern "C" {
#endif

void SkPathEffect_delete(void * pathEffect);
int SkPathEffect_asADash(void *path_effect, void *info);
bool SkPathEffect_filterPath(void *path_effect, void *dst, const void *src, void *rec, const void *cullR);
bool SkPathEffect_filterPath_2(void *path_effect, void *dst, const void *src, void *rec, const void *cullR, const void *ctm);
bool SkPathEffect_needsCTM(void *path_effect);
int SkPathEffect_getFactory(void *path_effect);
const char * SkPathEffect_getTypeName(void *path_effect);
void SkPathEffect_flatten(void *path_effect, void *buffer);
int SkPathEffect_getFlattenableType(void *path_effect);
int SkPathEffect_serialize(void *path_effect, const void *procs);
unsigned long SkPathEffect_serialize_2(void *path_effect, void *memory, unsigned long memory_size, const void *procs);
bool SkPathEffect_unique(void *path_effect);
void SkPathEffect_ref(void *path_effect);
void SkPathEffect_unref(void *path_effect);

// static

int SkPathEffect_MakeSum(int first, int second);
int SkPathEffect_MakeCompose(int outer, int inner);
int SkPathEffect_GetFlattenableType();
int SkPathEffect_Deserialize(const void *data, unsigned long size, const void *procs);
int SkPathEffect_NameToFactory(const char name[]);
const char * SkPathEffect_FactoryToName(int factory);
void SkPathEffect_Register(const char name[], int factory);

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_PATH_EFFECT_H
