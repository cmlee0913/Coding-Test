def solution(id_list, report, k):
    set_report=list(set(report))
    warning=[0]*len(id_list) # 경고횟수 카운트
    answer=[0]*len(id_list)
    for i in range(len(set_report)):
        warning[id_list.index(set_report[i].split()[1])]+=1
    for i in range(len(warning)):
        if(warning[i]>=k):
            for j in range(len(set_report)):
                if(set_report[j].split()[1]==id_list[i]):
                    answer[id_list.index(set_report[j].split()[0])]+=1
    return answer