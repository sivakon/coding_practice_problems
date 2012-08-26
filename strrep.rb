class Array
    def check_all_odd
        self.each do |i|
            if i.even?
                return false
            else
                next
            end
        end
        return  true
    end
    def check_all_even
        self.each do |i|
            if i.odd?
                return false
            else
                next
            end
        end
        return true
    end
    def check_zeros
        if self.count(0)>=2
            temp=self.sort.reverse
            temp.pop(2)
            return temp
        else
            return false     
        end
    end
end

T=gets.to_i
for i in 1..T
   c = Array[0,0,0]
   a=gets.chomp
   c[0] = a.scan(/a/).length
   c[1] = a.scan(/b/).length
   c[2] = a.scan(/c/).length
   #p c
   if c.check_zeros
    puts c.check_zeros
   elsif c.check_all_odd || c.check_all_even
    puts "2".to_i   
   else
    puts "1".to_i
  end
   
end