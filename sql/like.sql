SELECT INS.ANIMAL_ID, INS.ANIMAL_TYPE, INS.NAME
FROM ANIMAL_INS AS INS
INNER JOIN ANIMAL_OUTS AS OUTS
ON INS.ANIMAL_ID = OUTS.ANIMAL_ID
WHERE (INS.SEX_UPON_INTAKE NOT LIKE '%Spayed%' AND INS.SEX_UPON_INTAKE NOT LIKE '%Neutered%') 
AND (OUTS.SEX_UPON_OUTCOME LIKE '%Spayed%' OR OUTS.SEX_UPON_OUTCOME LIKE '%Neutered%')
ORDER BY INS.ANIMAL_ID