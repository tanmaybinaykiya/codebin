class QuestionCard extends React.Component{
	constructor(props) {
        super(props);
    }

	render(){
		return(
			<div id="questionCard">
				<div id="questionCardTitle"><span>Tell us about your trip</span></div>
				<FormCard />
			</div>
		);
	}
}