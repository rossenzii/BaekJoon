# 년, 월, 성별 별로 상품을 구매한 회원수를 집계하는 SQL문 / 결과는 년, 월, 성별을 기준으로 오름차순 정렬해주세요. 이때, 성별 정보가 없는 경우 결과에서 제외

select year(os.sales_date) as year,
    month(os.sales_date) as month,
    ui.gender as gender,
    count(distinct ui.user_id) as users
from online_sale os
join user_info ui on ui.user_id=os.user_id
where ui.gender is not null
group by year(os.sales_date), month(os.sales_date), ui.gender
order by year asc, month asc, gender asc;