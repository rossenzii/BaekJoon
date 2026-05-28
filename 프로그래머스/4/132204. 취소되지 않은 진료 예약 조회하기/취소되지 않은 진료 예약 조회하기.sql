# 2022년 4월 13일 취소되지 않은 흉부외과(CS) 진료 예약 내역을 조회하는 SQL문
# 진료예약번호, 환자이름, 환자번호, 진료과코드, 의사이름, 진료예약일시
# 진료예약일시를 기준으로 오름차순 정렬
select A.APNT_NO, P.PT_NAME, P.PT_NO, D.MCDP_CD, D.DR_NAME, A.APNT_YMD
from APPOINTMENT A
join PATIENT P on P.PT_NO=A.PT_NO
join DOCTOR D on D.DR_ID=A.MDDR_ID
where A.APNT_YMD>='2022-04-13' and A.APNT_YMD<'2022-04-14' and A.APNT_CNCL_YMD is null and A.MCDP_CD='CS'
order by A.APNT_YMD asc;