SET @UNITHOUR = -1;
SELECT 
(@UNITHOUR := @UNITHOUR + 1) AS HOUR,
(SELECT COUNT(HOUR(DATETIME)) FROM ANIMAL_OUTS WHERE HOUR(DATETIME) = @UNITHOUR) AS COUNT
FROM ANIMAL_OUTS
WHERE @UNITHOUR < 23

/*
 변수 초기화
# SET @변수명 = a;

# 변수 갱신
# (@변수명 := b)
*/