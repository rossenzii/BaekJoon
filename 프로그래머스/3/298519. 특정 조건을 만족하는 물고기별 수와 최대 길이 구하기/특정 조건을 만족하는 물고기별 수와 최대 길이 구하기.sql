select count(*) FISH_COUNT,
        max(LENGTH) MAX_LENGTH,
        FISH_TYPE
from FISH_INFO
group by FISH_TYPE
having avg(IFNULL(LENGTH, 10)) >= 33
order by FISH_TYPE