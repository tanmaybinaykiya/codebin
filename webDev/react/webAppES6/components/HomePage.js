class HomePage extends React.Component{
	constructor(props) {
        super(props);
    }

	render(){
		return (
		<div className="homePage">
			<div id="welcomeText"><span>Find all you will need on your trip, faster, with Vacation</span></div>
			<QuestionCard />
		</div>
		);
	}
}

