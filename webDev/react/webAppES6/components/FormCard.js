class FormCard extends React.Component{
	constructor(props) {
        super(props);
    }

	submitHandler(obj){
		console.log("submitHandler");
		console.log(obj);
	}

	handleSubmit(obj){
		console.log("handleSubmit");
		console.log(obj);
	}

	render(){
		return (
			<div className="formCard">
				<form onSubmit={this.handleSubmit}>
					<SelectForm msg="Which place are you visiting?" options={
						[{	
							name:'Barcelona',
							value:'BAR'
						},{
							name:'Leh/Ladakh',
							value:'LEH',
							isDefault: true
						},{
							name:'Goa',
							value:'GOA'
						}] 
					} />
					<RadioForm msg="What are the activities you are looking forward to?" options={
						[{
							name:'Business',
							value:'BSNS',
						}, {
							name:'Swimming/Beach',
							value:'SWIM'
						}, {
							name:'Hiking/Trek',
							value:'HIKE',
							isDefault: true
						}, {
							name:'Clubbing',
							value:'CLUB'
						}, {
							name:'Sightseeing',
							value:'SIGT'
						}] 
					} />
					<div className="subForm">
						<button id="submitButton" type="submit" value="submit"  >Lets Get Started</button>
					</div>
				</form>
			</div>
		);
	}
}

FormCard.defaultProps={
					place:'barc', 
					activity:['swim', 'sightsee']
				};