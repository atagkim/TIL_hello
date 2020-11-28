SELECT NAME, COUNT(NAME) CNT
FROM ANIMAL_INS
WHERE NAME IS NOT NULL
GROUP BY NAME
HAVING CNT > 1
ORDER BY NAME