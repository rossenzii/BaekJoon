# 자동차 종류가 '트럭'인 자동차의 대여 기록에 대해서 대여 기록 별로 대여 금액(컬럼명: FEE)을 구하여 
#대여 기록 ID와 대여 금액 리스트를 출력하는 SQL문을 작성
#결과는 대여 금액을 기준으로 내림차순 정렬하고, 대여 금액이 같은 경우 대여 기록 ID를 기준으로 내림차순 정렬
select rh.history_id, 
    round(
        cc.daily_fee
        * (datediff(rh.end_date, rh.start_date) +1)
        * (1-ifnull(dp.discount_rate, 0)/100)
    ) as fee
from car_rental_company_rental_history rh
join car_rental_company_car cc on cc.car_id=rh.car_id
left join car_rental_company_discount_plan dp 
    on dp.car_type=cc.car_type
    and dp.duration_type = (
        case 
            when datediff(rh.end_date, rh.start_date) + 1 >=90 then '90일 이상'
            when datediff(rh.end_date, rh.start_date) + 1 >=30 then '30일 이상'
            when datediff(rh.end_date, rh.start_date) + 1 >=7 then '7일 이상'
            else null
        end
    )
where cc.car_type='트럭'
order by fee desc, history_id desc;