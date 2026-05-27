select I.ID, 
        N.FISH_NAME, 
        I.LENGTH
from FISH_INFO I
left join FISH_NAME_INFO N on N.FISH_TYPE = I.FISH_TYPE
where (I.FISH_TYPE, I.LENGTH) in (
    select FISH_TYPE, MAX(LENGTH)
    from FISH_INFO
    group by FISH_TYPE
)
order by I.ID;