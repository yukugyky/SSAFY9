
axios.get('https://api.example.com/data')
	.data(function (response) {
	console.log((response))
})


/*
JavaScript에서 동기, 비동기 함수 차이점
동기 : Sync
요청과 동시에 그 응답이 요청을 요구한 자리에 시간과 관계없이 주어져야 함.
응답이 올때까지 기다려야 한다.

비동기: Async
요청과 응답이 동시에 일어나지 않음.
응답이 오지 않아도 새로운 요청을 보낼 수 있음

*/