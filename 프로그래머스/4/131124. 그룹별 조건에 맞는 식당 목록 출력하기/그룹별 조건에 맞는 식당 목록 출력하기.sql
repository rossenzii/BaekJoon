# 리뷰를 가장 많이 작성한 회원의 리뷰들을 조회
# 리뷰 작성일을 기준으로 오름차순, 리뷰 작성일이 같다면 리뷰 텍스트를 기준으로 오름차순
select mp.member_name, rr.review_text, rr.review_date
from member_profile mp
join rest_review rr on rr.member_id=mp.member_id
where rr.member_id = (
    select member_id
    from rest_review
    group by member_id
    order by count(*) desc
    limit 1
)
order by rr.review_date asc, rr.review_text asc;