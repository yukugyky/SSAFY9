const nums = [1, 2, 3, 4];
const nums2=[];

const cube=(b)=>b*b*b;
for(let i=0;i<nums.length;i++){
    nums2[i]=cube(nums[i]);
}