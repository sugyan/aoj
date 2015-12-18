def move(src, des, t, f, p, costs, r, c, a)
  if src == des
    return [t, a]
  end
  ret = [0, a]
  f[src[0]][src[1]] = '@'
  [[-1, 0], [0, -1], [0, 1], [1, 0]].each do |d|
    i, j = src[0] + d[0], src[1] + d[1]
    if i >= 0 && j >= 0 && i < r && j < c && f[i][j] == '.'
      ret = move([i, j], des, t + 1, f, p, costs, r, c, a)
      if ret[0] > 0
        cost = costs[1][i][j] + costs[2][i][j]
        ret[1] += cost
        if p[i][j]
          d = (t - p[i][j]) * costs[0][i][j] - cost
          ret[1] += d if d < 0
        end
        p[i][j] = t
        break
      end
    end
  end
  f[src[0]][src[1]] = '.'
  ret
end
def calc(f, costs, tasks, r, c, m)
  i0, j0 = tasks[0][0], tasks[0][1]
  p = Array.new(c){ [] }
  p[i0][j0] = 1
  t = 2
  a = costs[1][i0][j0] + costs[2][i0][j0]
  tasks.each_cons(2) do |task|
     t, a = move(*task, t, f, p, costs, r, c, a)
  end
  a
end
1.times do
  f = [], costs = [], tasks = []
  r, c, m = gets.split.map(&:to_i)
  r.times do |i|
    f[i] = gets.chomp.split('')
  end
  3.times do |k|
    costs[k] = []
    r.times do |i|
      costs[k][i] = gets.split.map(&:to_i)
    end
  end
  m.times do |i|
    tasks[i] = gets.split.map(&:to_i)
  end
  puts calc(f, costs, tasks, r, c, m)
end
