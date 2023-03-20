<template>
  <div id="app">
    <h1>Hello Vue</h1>
    <LineChart />
    <DataSendForm/>
  </div>
</template>

<script>
import DataSendForm from "./components/DataSendForm.vue"
import {dataLab} from "./utils/axios";
import {mapState, mapMutations } from 'vuex';
import LineChart from "./components/LineChart";
export default {
  name: "App",
  components: { LineChart, DataSendForm },
  computed : {
    ...mapState(["chartData"]),
  },
  async created(){
    try{
    const response = await dataLab.get();
    console.log(response.data);

    const first = response.data[0];
    const labels=first.data.map((item)=>item.period);
    console.log(labels);

    const datasets=response.data.map((item)=>{
      return{
        label: item.title,
        borderColor:this.makeColor(),
        data: item.data.map((item)=>item.ratio),
        tension: 0.3,

      }
    })
    const chartData={
      labels:labels,
      datasets:datasets,
    }
    this.CHANGE_CHART_DATA(chartData);
    console.log(this.chartData);
  } catch (error){
    console.log(error);
  }
  },
  methods: {
    ...mapMutations(["CHANGE_CHART_DATA"]),
    makeColor(){
      return "#"+Math.round(Math.random()*0xffffff).toString(16);
    }
  }
};

</script>

<style>

</style>