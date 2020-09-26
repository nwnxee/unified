
//Same as EffectDamageReduction, but you can set a material
effect EffectDamageReductionExt(int nAmount, int nDamagePower, int nMaterial, int nLimit=0);

//Same as EffectImmunity, but can set a %. Critical hits and sneak attacks ONLY
effect EffectImmunityExt(int nImmunityType, int nPercent);

effect EffectDamageReductionExt(int nAmount, int nDamagePower, int nMaterial, int nLimit=0)
{
    effect e = EffectDamageReduction(nAmount, nDamagePower, nLimit);
    struct NWNX_EffectUnpacked unpacked = NWNX_Effect_UnpackEffect(e);
    unpacked.nParam3=nMaterial;
    return NWNX_Effect_PackEffect(unpacked);
}

effect EffectImmunityExt(int nImmunityType, int nPercent)
{
    effect e =  EffectImmunity(nImmunityType);
    if(nImmunityType != IMMUNITY_TYPE_SNEAK_ATTACK && nImmunityType != IMMUNITY_TYPE_CRITICAL_HIT)
        return e;
    struct NWNX_EffectUnpacked unpacked = NWNX_Effect_UnpackEffect(e);
    unpacked.nParam4=nPercent;
    return NWNX_Effect_PackEffect(unpacked);
}
