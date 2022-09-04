// HLSL 언어 (하이 레벨 쉐이더 랭귀지)
// 정점 쉐이더. 
// 정점쉐이더란 정점버퍼에 있는 모든 정점을 한번씩 작업한다.
// 정점위치는 반드시 float4로 SV_POSITION 레지스터에 반환해야 한다. (등초좌표계? 일단 지금은 몰?루도 됨)
// POSITION -> 시멘틱 : 의미구조, 이름은 멋대로 정해도 되기는 함 ㅋㅋ


// Vertex Shader,줄여서 VS       즉 얘는 고정            
float4 VS(float3 p : POSITION) : SV_POSITION // <- 시스템 밸류 포지션, 반드시 지정된 장소(SV_POSITION)에 정점위치를 넘겨줘야함.
{
	//float4(px, py, pz, 1.0f) == float4(p, 1.0f) 이런걸 수의즐링이라고 한다
	return float4(p, 1.0f);
}

//float4 VS(float3 p : POSITION, float4 c : COLOR) : SV_POSITION       
//{
//	return float4(p, 1.0f);
//}